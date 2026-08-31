# Program 2(a)
# Polynomial Regression using Student Score Dataset

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression

# Step 1: Load the dataset
data = pd.read_csv("student_scores.csv")

# Step 2: Separate input and output
X = data[["Hours"]]
y = data["Marks"]

# Step 3: Create polynomial features
degree = 2
poly = PolynomialFeatures(degree=degree)

X_poly = poly.fit_transform(X)

# Step 4: Create and train the model
model = LinearRegression()
model.fit(X_poly, y)

# Step 5: Predict marks
y_pred = model.predict(X_poly)

# Step 6: Display model coefficients
print("Polynomial Regression Model")
print("Intercept:", model.intercept_)
print("Coefficients:", model.coef_)

# Step 7: Predict marks for a new student
hours = np.array([[7.5]])
hours_poly = poly.transform(hours)

prediction = model.predict(hours_poly)

print("Predicted marks for 7.5 hours:", prediction[0])

# Step 8: Plot actual data
plt.scatter(X, y, label="Actual Data")

# Step 9: Plot polynomial regression curve
X_range = np.linspace(X.min(), X.max(), 100).reshape(-1, 1)
X_range_poly = poly.transform(X_range)
y_range_pred = model.predict(X_range_poly)

plt.plot(X_range, y_range_pred, label="Polynomial Regression")

plt.xlabel("Hours Studied")
plt.ylabel("Marks")
plt.title("Polynomial Regression - Student Scores")
plt.legend()
plt.grid(True)
plt.show()