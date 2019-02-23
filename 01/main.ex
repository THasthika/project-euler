defmodule Prog do

    @limit 1000

    def run() do
        recur(@limit-1)
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
