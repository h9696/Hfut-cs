from cmath import sqrt
import numpy as np
'''
   拉格朗日插值函数
'''

# 定义拉格朗日插值函数
def lagrange_interpolation(x, y, xi):
    n = len(x)
    yi = 0
    for i in range(n):
        li = 1
        for j in range(n):
            if j!= i:
                li *= (xi - x[j]) / (x[i] - x[j])
        yi += li * y[i]
    return yi


# 生成示例数据点（以y = sqrt(x)为例，选择区间[100, 121]）
x_data = np.linspace(100, 121, 5)  # 在[100, 121]区间内生成5个等间距的点作为已知数据点的x坐标
y_data = np.sqrt(x_data)  # 对应的y坐标，根据y = sqrt(x)计算得到

# 设置要插值的目标值（即求sqrt(115)）
x_interp = np.array([115])  # 只包含115这一个值，作为要插值计算的目标x值

# 进行拉格朗日插值计算
y_interp = [lagrange_interpolation(x_data, y_data, xi) for xi in x_interp]

# 获取逼近的sqrt(115)的值
approx_sqrt_115 = y_interp[0]
print("sqrt(115)的值:", sqrt(115))
print("逼近的sqrt(115)的值:", approx_sqrt_115)
