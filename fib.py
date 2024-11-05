def iterative(n):
    if n <=1: return n,n
    f = [0, 1] + [0] * (n-1)
    for i in range(2, n+1):
        f[i] = f[i-1] + f[i-2]
    return f[n], n

r_steps =0
def recursive(n):
    global r_steps
    r_steps+= 1
    return n if n<=1 else recursive(n-1) + recursive(n-2)

n= int(input("Enter the no. : "))
fib_itr, step_itr = iterative(n)
print(f"Fibonacci Recursion value : {recursive(n)}")
print(f"Fibonacci (Iteration) Value : {fib_itr} Steps : {step_itr} ")
print(f"Steps required using recursion : {r_steps} ")