# Program 2(b)
# Polynomial Regression using Auto MPG Dataset

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score

# Step 1: Define column names
column_names = [
    "mpg",
    "cylinders",
    "displacement",
    "horsepower",
    "weight",
    "acceleration",
    "model_year",
    "origin",
    "car_name"
]

# Step 2: Load the Auto MPG dataset
data = pd.read_csv(
    "auto-mpg.data",
    sep=r"\s+",
    names=column_names,
    na_values="?"
)

# Step 3: Remove rows containing missing values
data = data.dropna()

# Step 4: Display first five records
print("First five records:")
print(data.head())

# Step 5: Select independent and dependent variables
X = data[["weight"]]
y = data["mpg"]

# Step 6: Create polynomial features
degree = 2

poly = PolynomialFeatures(degree=degree)

X_poly = poly.fit_transform(X)

# Step 7: Create Linear Regression model
model = LinearRegression()

# Step 8: Train the model
model.fit(X_poly, y)

# Step 9: Predict MPG
y_pred = model.predict(X_poly)

# Step 10: Display model information
print("\nPolynomial Regression Model")
print("Intercept:", model.intercept_)
print("Coefficients:", model.coef_)

# Step 11: Calculate performance
mse = mean_squared_error(y, y_pred)
r2 = r2_score(y, y_pred)

print("\nMean Squared Error:", mse)
print("R² Score:", r2)

# Step 12: Predict MPG for a new car
new_weight = np.array([[3000]])

new_weight_poly = poly.transform(new_weight)

predicted_mpg = model.predict(new_weight_poly)

print("\nPredicted MPG for a car weighing 3000:")
print(predicted_mpg[0])

# Step 13: Create values for smooth regression curve
X_range = np.linspace(
    X["weight"].min(),
    X["weight"].max(),
    200
).reshape(-1, 1)

X_range_poly = poly.transform(X_range)

y_range_pred = model.predict(X_range_poly)

# Step 14: Plot actual data points
plt.scatter(
    X["weight"],
    y,
    label="Actual Data"
)

# Step 15: Plot polynomial regression curve
plt.plot(
    X_range,
    y_range_pred,
    label="Polynomial Regression"
)

# Step 16: Add labels and title
plt.xlabel("Vehicle Weight")
plt.ylabel("Miles Per Gallon (MPG)")
plt.title("Polynomial Regression - Auto MPG Dataset")

plt.legend()
plt.grid(True)

# Step 17: Display graph
plt.show()