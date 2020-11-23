# Timexで時間操作
Phoenixでプロジェクトを作っているときに、

- 指定時間にプログラムを実行したい
- 時刻の足し算、引き算がしたい（１時間後とか２日前とか）
- 日時の処理を`DateTime`よりも直感的に行いたい

など、時刻をいじる系で便利な手段が欲しくなることがあると思います。
そういうときに使えるのがこの**Timex**というモジュールです。

今回は新規プロジェクトの中で[Timex](https://hexdocs.pm/timex/Timex.html)を用いて色々な操作をしてみようと思います。Elixirを触りたての方でも十分理解できるような内容となっていると思います。

## Timexとは
時間操作用のモジュールです。Linuxでよく使われる、**tzdata**というタイムゾーンのデータの入ったパッケージを利用しています。
Elixirに標準でついている`Time`構造体や`Date`構造体などは時刻しか扱えなかったり日付しか扱えなかったりで不便な思いをしてしまったり、プログラムであれこれ処理をしようとすると長くなってしまったりして読みにくい思いをしてしまうことがあると思います。
この**Timex**は豊富な機能を持ちながら、簡潔に時間操作が行えるのでそのような場合に人気のモジュールです。

## プロジェクト新規作成
```bash
> mix phx.new toki --no-ecto --no-webpack
```
今回はectoとwebpackは使わずに動作をさせてみようと思います。

```elixir:mix.exs
  # Specifies your project dependencies.
  #
  # Type `mix help deps` for examples and options.
  defp deps do
    [
      {:phoenix, "~> 1.5.6"},
      {:phoenix_html, "~> 2.11"},
      {:phoenix_live_reload, "~> 1.2", only: :dev},
      {:phoenix_live_dashboard, "~> 0.3 or ~> 0.2.9"},
      {:telemetry_metrics, "~> 0.4"},
      {:telemetry_poller, "~> 0.4"},
      {:gettext, "~> 0.11"},
      {:jason, "~> 1.0"},
      {:plug_cowboy, "~> 2.0"},
      {:timex, "~> 3.0"}
    ]
  end
```
`mix.exs`でtimexを入れて、`mix deps.get`をします。

```bash
> iex -S mix phx.server
```

そしてサーバーを起動しておきます。これで準備完了です！

## 時刻関連のシギルたち
実際にコードを動かしてみる前に、Elixirの時関系でよく使われる**シギル**について触っておこうと思います。


### ~D
**Date**構造体用のテキスト表現です。
`year`, `month`, `day`, それと`calendar`というフィールドを持っています。
Date構造体は現在の日付に関する情報は持っていますが、時刻に関する情報は持っていません。

```elixir:Date
iex> d = ~D[2019-10-31]
~D[2019-10-31]
iex> d.day
31
```

### ~T
**Time**構造体用のテキスト表現です。
`hour`, `microsecond`, `minute`, `second`, それと`calendar`というフィールドを持っています。
こちらのTime構造体は現在の一日の時刻に関する情報は持っていますが、年月日に関する情報は持っていません。

```elixir:Time
iex> t = ~T[23:00:07.0]
~T[23:00:07.0]
iex> t.second
7
```

### ~N
**NaiveDateTime**構造体用のテキスト表現です。
NaiveDateTimeは日付と時刻の両方の情報を持っています。しかし、タイムゾーンに関する情報は持っていません。

```elixir:NaiveDateTime
iex> ndt = ~N[2019-10-31 23:00:07]
~N[2019-10-31 23:00:07]
```

### ~U
**DateTime**構造体用のテキスト表現です。UTC時刻のISOフォーマットらしいです。
DateTimeは、NaiveDateTimeにタイムゾーンの情報を付け足したような構造体です。

```elixir:DateTime
iex> dt = ~U[2019-10-31 19:59:03Z]
~U[2019-10-31 19:59:03Z]
iex> %DateTime{minute: minute, time_zone: time_zone} = dt
~U[2019-10-31 19:59:03Z]
iex> minute
59
iex> time_zone
"Etc/UTC"
```

## 現在時刻の取得
最初は一番わかりやすく、手っ取り早い現在時刻の取得からやってみます。

```bash
iex(1)> use Timex
Timex.Timezone
iex(2)> Timex.now()
~U[2020-11-23 15:58:54.967055Z]
```

カンタンに取得できました。

```bash
iex(3)> Timex.now("America/Chicago")
#DateTime<2020-11-23 09:59:08.108933-06:00 CST America/Chicago>
iex(4)> Timex.now("Asia/Tokyo")
#DateTime<2020-11-24 01:01:19.534768+09:00 JST Asia/Tokyo>
```

タイムゾーンの指定もこのようにして行うことができます。

## タイムゾーンの取得
よく出てくるタイムゾーンの一覧を取得するには、`timezones/0`関数を使います。

```elixir
Timex.timezones() |> IO.inspect(limit: :infinity)
```

`IO.inspect()`なしで結果を表示しようとすると途中から省略されてしまうので、
このようにして`IO.inspect(data, limit: :infinity)`をパイプラインで繋げることでリストを全て表示することができると思います。

## 他の構造体へ変換する
Elixirに標準で用意されている`Date`構造体や`DateTime`構造体などにも簡単に変換することができます。

```elixir
iex(8)> Timex.now() |> Timex.to_date()
~D[2020-11-23]
iex(9)> Timex.now() |> Timex.to_datetime()
~U[2020-11-23 16:53:23.198898Z]
iex(10)> Timex.now() |> Timex.to_unix()
1606150431
iex(11)> Timex.now() |> Timex.to_naive_datetime()
~N[2020-11-23 16:54:16.577036]
```

## 特定の日付よりも前か後かを判定
ここまでの過程で、Timexを他の構造体へ変換してきました。これを利用することで時間にまつわる様々な情報を得ることができます。
ここでは、今日の日付がクリスマスよりも前なのか後なのかを判定させています。

```elixir
iex(13)> Timex.now() |> Timex.to_date()
~D[2020-11-23]
# クリスマスよりも後かどうか
iex(14)> Timex.after?(~D[2020-11-23], ~D[2020-12-25])
false
# クリスマスよりも前かどうか
iex(15)> Timex.before?(~D[2020-11-23], ~D[2020-12-25])
true
```

## ずらした日にち（明日とか）を取得する
これはけっこう使い勝手の良い処理だと思います。この例では明日や昨日を取得しています。
Timexの中にある`Duration`モジュールも使用しています。

```elixir
# 明日
iex(19)> Timex.now() |> Timex.add(Timex.Duration.from_days(1))
~U[2020-11-24 17:11:10.458624Z]
# 昨日
iex(20)> Timex.now() |> Timex.add(Timex.Duration.from_days(-1))
~U[2020-11-22 17:12:14.499312Z]
# 来週
iex(21)> Timex.now() |> Timex.add(Timex.Duration.from_weeks(1))
~U[2020-11-30 17:14:28.370927Z]
```

`Timex.add/2`の他にも、`Timex.shift/2`を利用することができます。

```elixir
# 来年
iex(25)> Timex.now() |> Timex.to_date() |> Timex.shift(years: 1)
~D[2021-11-23]
# 明日
iex(28)> Timex.now() |> Timex.to_date() |> Timex.shift(days: 1)
~D[2020-11-24]
```

## 時刻にまつわる文字列を解析する
これも使いやすいと思います。指定されたフォーマットで書かれた文字列をパースして取り込むことができます。
文字列として時刻を渡されたときに重宝するかと思います。

```elixir
iex(22)> Timex.parse("2020-11-24", "{YYYY}-{0M}-{D}")
{:ok, ~N[2020-11-24 00:00:00]}
iex(23)> Timex.parse("2020-11-24T22:25:00-00:00", "{ISO:Extended}")
{:ok, ~U[2020-11-24 22:25:00Z]}
iex(24)> Timex.parse("2020-11-24T22:25:00-00:00Z", "{ISO:Extended}")
{:ok, ~U[2020-11-24 22:25:00Z]}
```

# さいごに
今回はTimexの中でも使い勝手のいい機能たちを掲載させていただきました。Elixirでアプリケーションを開発するときにTimexに触れる機会は出てくると思うので、少しでも助けになれば幸いです！

# 参考リンク
> https://elixir-lang.org/getting-started/sigils.html
> https://elixirschool.com/ja/lessons/basics/date-time/
> https://hexdocs.pm/timex/Timex.html
> https://access.redhat.com/ja/articles/3296191
