defmodule Memoizer do

  use GenServer

  def start_link(opts \\ []) do
    GenServer.start_link(__MODULE__, :ok, opts)
  end

  def stop(pid, reason \\ :normal, timeout \\ :infinity) do
    GenServer.stop(pid, reason, timeout)
  end

  def get(pid, k) do
    GenServer.call(pid, {:get, k})
  end

  def set(pid, k, v) do
    GenServer.call(pid, {:set, {k, v}})
  end

  ## GENSERVER CLASSBACKS
  def init(:ok) do
    {:ok, %{0 => 1, 1 => 1}}
  end

  def handle_call({:get, k}, _from, kv) do
    {:reply, Map.get(kv, k, :nil), kv}
  end

  def handle_call({:set, {k, v}}, _from, kv) do
    {:reply, :ok, Map.put(kv, k, v)}
  end

  def terminate(_reason, _state) do
    :normal
  end

end

defmodule Prog do

  @limit 4000000

  def run do
    {:ok, mem} = Memoizer.start_link()
    v = recur(mem)
    Memoizer.stop(mem)
    v
  end

  def recur(p, n \\ 1, t \\ 0) do
    v = fib(n, p)
    if v >= @limit do
      t
    else
      if rem(v, 2) == 0 do
        recur(p, n+1, t+v)
      else
        recur(p, n+1, t)
      end
    end
  end

  def fib(0, _p) do
    1
  end
  def fib(1, _p) do
    1
  end
  def fib(n, p) do
    v = Memoizer.get(p, n)
    case v do
      :nil ->
        v = fib(n-1, p) + fib(n-2, p)
        Memoizer.set(p, n, v)
        v
      _ ->
        v
    end
  end



end
