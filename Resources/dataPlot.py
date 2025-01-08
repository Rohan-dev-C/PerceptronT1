import pandas as pd
import matplotlib.pyplot as plt


file_path = 'TESLA.csv'
data = pd.read_csv(file_path)

x = data['Open']
y = data['Close']

plt.figure(figsize=(10, 6))
plt.scatter(x, y, alpha=0.5)
plt.title('Tesla Stock Prices: Open vs. Close')
plt.xlabel('Open Price')
plt.ylabel('Close Price')

slope = -0.51
intercept = -9.8
line_y = slope * x + intercept
plt.plot(x, line_y, color='red', label='Line: y = -0.51x - 9.8')

plt.show()
