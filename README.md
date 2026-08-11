# d60_split_rshift

DZ60（60% キーボード、右Shift分割配列）向けの QMK キーマップです。

## コードの特徴

**US物理配列のキーボードでJIS(日本語)入力を行うためのカスタムキーコード**が中心です。KBDFans DZ60（US配列ハードウェア）に、日本語(JIS)配列相当の記号入力を割り当てています。

### レイヤー構成（`dz60/keymaps/60_split_rshift/keymap.c`）

| レイヤー | 役割 |
|---|---|
| `_USBL` | US配列ベースレイヤー |
| `_USFL` | USファンクションレイヤー（矢印キー、PrintScreen、Home/End など） |
| `_JPBL` | JIS(日本語)配列ベースレイヤー |
| `_JPFL` | JPファンクションレイヤー（マウス操作 + 矢印キー） |
| `_ADJUST` | US/JIS切り替え・ブートローダー起動用の調整レイヤー |

`_ADJUST` レイヤーの `US`/`JIS` キーで `set_single_persistent_default_layer()` を呼び出し、デフォルトレイヤーをEEPROMに保存して起動時のUS/JIS配列を切り替えます。

### JIS/USシフト変換の仕組み

物理的にはUS配列のキーを押しているのに、JISとして解釈させたい記号（`@` `&` `*` `(` `)` など）を出力するため、`JU_2` `JU_6` `JU_7`〜`JU_0` `JU_MINS` `JU_EQL` `JU_LBRC` `JU_RBRC` `JU_BSLS` `JU_SCLN` `JU_QUOT` `JU_GESC` `JU_BSPC` というカスタムキーコードを定義し、`process_record_user()` の中で押下時のShift状態を見て送信するキーコードを動的に切り替えています。

- Shiftを押しながら押下 → JIS配列上の対応する記号キーコード（`JP_AT` など）を送信
- Shiftなしで押下 → 通常のキーコード（`KC_2` など）を送信

キーを離す際は、押した瞬間に読み取ったShift状態（`lshift`/`rshift`）を見て、送信したキーコードの解除と本物のShiftキーの再登録を行います。

> **既知の不具合**: `lshift`/`rshift` はすべてのカスタムキーで共有されるstatic変数のため、複数のカスタムキーを跨いだロールオーバー入力で状態が食い違うことがあります。また、Shiftを押しながら記号キーを押し、記号キーを離す前にShiftだけ先に離すといった高速タイピングの入力順では、離すときの処理が「押した瞬間はShiftが押されていた」という古い情報を信じてShiftを再登録してしまい、Shiftが押しっぱなし状態でスタックする（例：Shiftを離した後でも `2` を押すと `@` が出続ける）ことがあります。この問題の修正は別PR（[#1](../../pull/1)）で対応しています。

### ビルド方法

このリポジトリの `dz60/` は [QMK Firmware](https://github.com/qmk/qmk_firmware) の `keyboards/dz60` 配下にコピーして使うキーボード定義です。

#### QMK CLIが手元にある場合
```sh
$ cp -R dz60 qmk_firmware/keyboards/dz60
$ cd qmk_firmware
$ make dz60:60_split_rshift
```

#### Docker を使う場合（ローカルにQMK環境がなくてもビルド可能）
```sh
# qmk_firmware をクローンし、AVRビルドに必要なサブモジュールだけ取得
$ git clone --depth 1 https://github.com/qmk/qmk_firmware.git
$ cd qmk_firmware
$ git submodule update --init --depth 1 lib/lufa lib/printf

# このリポジトリのキーマップだけをコピー（keyboard.json 等は公式のものを使う）
$ cp -R ../d60_split_rshift/dz60/keymaps/60_split_rshift keyboards/dz60/keymaps/60_split_rshift

# 公式イメージでビルド
$ docker pull qmkfm/qmk_cli
$ docker run --rm -v "$(pwd):/qmk_firmware" -w /qmk_firmware qmkfm/qmk_cli \
    qmk compile -kb dz60 -km 60_split_rshift
```
生成された `dz60_60_split_rshift.hex` を書き込みツール（QMK Toolbox など）でDZ60に書き込みます。

## 既知の注意点

- `dz60/keymaps/60_split_rshift/` には `keymap copy.c` `keymap_1.c` `keymap_2.c` `keymapJtoU.c.bak` などのバックアップ/試作ファイルが残っています。ビルドで実際に使われるのは `keymap.c` のみです。
- `jtu_custom_keycodes.c/.h`、`twpair_on_jis.c/.h` は `keymap.c` からincludeされておらず、現状のビルドには使用されていません（過去の共通化実装の名残）。
