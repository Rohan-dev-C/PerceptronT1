import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

file_path = 'TESLA.csv'
data = pd.read_csv(file_path)
x = data[['Open', 'High', 'Low']]
y = data['Close']
model = LinearRegression()
model.fit(x, y)

coefficients = model.coef_
intercept = model.intercept_

y_pred = model.predict(x)

fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')
scatter = ax.scatter(data['Open'], data['High'], data['Low'], c=y, cmap='viridis', alpha=0.6)

ax.plot_trisurf(data['Open'], data['High'], y_pred, alpha=0.2, color='red')

ax.set_title('3D Scatter Plot')
ax.set_xlabel('Open Price')
ax.set_ylabel('High Price')
ax.set_zlabel('Low Price')

colorbar = plt.colorbar(scatter)
colorbar.set_label('Close Price')

plt.figtext(0.15, 0.01, f'Coefficients: {coefficients}\nIntercept: {intercept:.2f}', fontsize=10, ha='left')

plt.show()
