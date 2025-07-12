def gaussian_elimination_with_steps(A):
    """
    使用高斯消元法求解线性方程组，并输出过程。

    参数:
        A: 增广矩阵 (list of lists)

    返回:
        解向量 (list)，或者 None (如果无解)。
    """
    n = len(A)

    print("初始增广矩阵:")
    print_matrix(A)

    # 前向消元过程
    for i in range(n):
        # 寻找当前列的主元
        max_row = i + max(range(n - i), key=lambda k: abs(A[i + k][i]), default=0)
        if abs(A[max_row][i]) < 1e-10:  # 判断主元是否接近 0
            print("无唯一解")
            return None
        # 交换行，将主元行移到当前行
        if max_row != i:
            A[i], A[max_row] = A[max_row], A[i]
            print(f"\n交换第 {i + 1} 行和第 {max_row + 1} 行:")
            print_matrix(A)

        # 消去第 i 行以下的元素
        for j in range(i + 1, n):
            factor = A[j][i] / A[i][i]
            print(f"\n第 {j + 1} 行 - 第 {i + 1} 行 * {factor:.6f}:")
            for k in range(i, n + 1):
                A[j][k] -= factor * A[i][k]
            print_matrix(A)

    # 回代过程
    x = [0] * n
    print("\n回代过程:")
    for i in range(n - 1, -1, -1):
        x[i] = A[i][n] / A[i][i]
        print(f"求解 x{i + 1}: {x[i]:.6f}")
        for j in range(i - 1, -1, -1):
            A[j][n] -= A[j][i] * x[i]
            print(f"更新第 {j + 1} 行: 减去第 {i + 1} 行 * {A[j][i]:.6f}")
        print_matrix(A)

    return x


def print_matrix(A):
    """
    格式化打印矩阵 A。
    """
    for row in A:
        print("  ".join(f"{elem:.6f}" for elem in row))
    print()


# 增广矩阵
A = [
    [2, -1, 3, 1],
    [4, 2, 5, 4],
    [1, 2, 0, 7]
]

# 调用高斯消元法求解
solution = gaussian_elimination_with_steps(A)

if solution:
    print("线性方程组的解为:")
    for i, x_i in enumerate(solution, 1):
        print(f"x{i} = {x_i:.6f}")