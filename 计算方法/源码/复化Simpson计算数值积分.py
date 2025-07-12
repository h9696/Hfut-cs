import numpy as np

def f(x):
    return np.exp(x) * np.cos(x)

def composite_simpson(f, a, b, n):
    if n % 2 == 1:
        raise ValueError("n must be an even number")
    h = (b - a) / n
    x = np.linspace(a, b, n+1)
    y = f(x)
    result = y[0] + y[-1] + 4 * np.sum(y[1:-1:2]) + 2 * np.sum(y[2:-1:2])
    return result * h / 3

# 定义积分区间
a = 0
b = np.pi

# 计算并打印不同n值的结果
n_values = [1, 2, 3, 4]
results = {}

for n in n_values:
    try:
        integral = composite_simpson(f, a, b, 2**n)
        results[2**n] = integral
    except ValueError as e:
        print(f"Error for n={2**n}: {e}")

# 打印结果
for n, result in results.items():
    print(f"n = {n}: 积分的近似值是 {result:.6f}")
