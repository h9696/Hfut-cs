import numpy as np

# 牛顿插值
def newton_interpolation(X, Y, init):
    sum = Y[0]
    temp = np.zeros((len(X), len(X)))

    # 将第一行赋值
    for i in range(len(X)):
        temp[i, 0] = Y[i]

    temp_sum = 1.0
    for i in range(1, len(X)):
        # x的多项式
        temp_sum = temp_sum * (init - X[i - 1])

        # 计算均差
        for j in range(i, len(X)):
            temp[j, i] = (temp[j, i - 1] - temp[j - 1, i - 1]) / (X[j] - X[j - i])
        sum += temp_sum * temp[i, i]
    return sum

# 拉格朗日插值
def lagrange_interpolation(X, Y, init):
    sum = 0.0
    for i in range(len(X)):
        temp = Y[i]
        for j in range(len(X)):
            if j != i:
                temp = temp * ((init - X[j]) / (X[i] - X[j]))
        sum = sum + temp
    return sum

def main():
    # 直接在代码中给出x和y的值
    X = np.array([1, 2, 4, 5, 6, 8])
    Y = np.array([0, 2, 8, 12, 18, 28])
    init = 5.8  # 需要插值的x坐标

    print("牛顿插值法：")
    choice = 2  # 选择插值方法

    if choice == 1:
        result = lagrange_interpolation(X, Y, init)
    else:
        result = newton_interpolation(X, Y, init)

    print("f(%f)的近似值为%f" % (init, result))

if __name__ == '__main__':
    main()