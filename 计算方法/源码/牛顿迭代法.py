import math


def newton_method(f, df, x0, tol=1e-6, max_iter=100):
    """
    使用牛顿迭代法求解非线性方程 f(x) = 0，并显示每次迭代的中间结果。

    参数:
        f: 函数对象，非线性方程 f(x)。
        df: 函数对象，f(x) 的导数 f'(x)。
        x0: 初始猜测值。
        tol: 容忍误差，迭代停止条件 (默认值: 1e-6)。
        max_iter: 最大迭代次数 (默认值: 100)。

    返回:
        解 x (若收敛)，或 None (若未收敛)。
    """
    x = x0
    for i in range(max_iter):
        fx = f(x)
        dfx = df(x)
        print(f"第 {i + 1} 次迭代:")
        print(f"x = {x:.6f}, f(x) = {fx:.6f}, f'(x) = {dfx:.6f}")

        if abs(fx) < tol:
            print(f"迭代收敛: x = {x}, f(x) = {fx}, 迭代次数 = {i + 1}")
            return x
        if dfx == 0:
            print("导数为零，无法继续迭代")
            return None
        x_new = x - fx / dfx
        error = abs(x_new - x)
        print(f"新解 x_new = {x_new:.6f}, 当前误差: {error:.6f}\n")
        x = x_new

    print("未能在最大迭代次数内收敛")
    return None


# 示例: 求解方程 x * e^x - 1 = 0
if __name__ == "__main__":
    # 定义函数和导数
    f = lambda x: x * math.exp(x) - 1
    df = lambda x: math.exp(x) * (x + 1)

    # 初始猜测值
    x0 = 0.6  # 可根据实际情况调整

    # 调用牛顿迭代法
    root = newton_method(f, df, x0)

    if root is not None:
        print(f"方程的近似解为: x = {root:.6f}")