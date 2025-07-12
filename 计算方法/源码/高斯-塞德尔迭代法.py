def gauss_seidel(A, b, tol=1e-6, max_iter=100):
    """
    使用高斯-塞德尔迭代法求解线性方程组 Ax = b，显示每次迭代的中间结果。

    参数:
        A: 系数矩阵 (list of lists or 2D array)。
        b: 常数项向量 (list or 1D array)。
        tol: 容忍误差，控制收敛精度 (默认值: 1e-6)。
        max_iter: 最大迭代次数 (默认值: 100)。

    返回:
        解向量 x (list) 或 None (未收敛)。
    """
    n = len(b)
    x = [0] * n  # 初始解向量 (全 0)

    for it in range(max_iter):
        x_new = x.copy()
        print(f"第 {it + 1} 次迭代:")
        for i in range(n):
            # 计算 x[i] 的新值
            sum1 = sum(A[i][j] * x_new[j] for j in range(i))  # 使用最新的值
            sum2 = sum(A[i][j] * x[j] for j in range(i + 1, n))  # 使用旧的值
            x_new[i] = (b[i] - sum1 - sum2) / A[i][i]

        # 输出当前迭代的解向量
        print(f"当前解: {x_new}")

        # 计算误差范数
        error = max(abs(x_new[i] - x[i]) for i in range(n))
        print(f"当前误差: {error}\n")

        if error < tol:
            print(f"迭代收敛: {it + 1} 次迭代后")
            return x_new
        x = x_new

    print("未能在最大迭代次数内收敛")
    return None


# 系数矩阵 A 和常数项向量 b (根据题目)
A = [
    [10, -1, -2],
    [-1, 10, -2],
    [-1, -1, 5]
]
b = [7.2, 8.3, 4.2]

# 调用高斯-塞德尔方法求解
solution = gauss_seidel(A, b)

if solution:
    print("线性方程组的解为:")
    for i, x_i in enumerate(solution, 1):
        print(f"x{i} = {x_i:.6f}")