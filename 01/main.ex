defmodule Prog do

    def run(n \\ 1000) do
        case n do
            x when x <= 0 ->
                0
            _ ->
                recur(n - 1)
        end
    end

    defp recur(n, t \\ 0)
    defp recur(n, t) when n <= 0 do
        t
    end
    defp recur(n, t) do
        n3 = rem(n, 3)
        n5 = rem(n, 5)
        case {n3, n5} do
            {x, y} when x == 0 or y == 0 ->
                recur(n-1, t+n)
            {_, _} ->
                recur(n-1, t)
        end
    end
end

defmodule Solution do

    def main() do
        t = IO.gets("") |> String.trim |> String.to_integer
        run_test_case(t)
    end

    defp run_test_case(t) when t <= 0 do
        :ok
    end
    defp run_test_case(t) do
        n = IO.gets("") |> String.trim |> String.to_integer
        a = Prog.run(n)
        IO.puts(a)
        run_test_case(t - 1)
    end

end

array_length = IO.read(:stdio, :line)
array = IO.read(:stdio, :line)

array_length
    |> String.trim
    |> String.to_integer
    |> IO.puts

array
    |> String.split(" ")
    |> Enum.map(fn n -> String.to_integer(n) end)
    |> IO.inspect