# 09-Locally-Weighted-Regression

import numpy as np
import matplotlib.pyplot as plt


# Generate sample data
X = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], dtype=float)
Y = np.array([2, 4, 5, 4, 5, 7, 8, 9, 10, 12], dtype=float)


# Locally Weighted Regression function
def locally_weighted_regression(x_query, X, Y, tau):
    # Calculate weights using Gaussian kernel
    weights = np.exp(-((X - x_query) ** 2) / (2 * tau ** 2))

    # Construct design matrix
    A = np.vstack([np.ones(len(X)), X]).T

    # Weight matrix
    W = np.diag(weights)

    # Calculate theta using weighted least squares
    theta = np.linalg.pinv(A.T @ W @ A) @ (A.T @ W @ Y)

    # Predict value at the given point
    prediction = np.array([1, x_query]) @ theta

    return prediction


# Bandwidth parameter
tau = 1.0

# Generate predictions around each point
X_test = np.linspace(1, 10, 100)
Y_pred = []

for x in X_test:
    y_pred = locally_weighted_regression(x, X, Y, tau)
    Y_pred.append(y_pred)


# Display prediction around a given point
given_point = 6
prediction = locally_weighted_regression(given_point, X, Y, tau)

print("Given Point:", given_point)
print("Predicted Value:", prediction)


# Plot the data and locally weighted regression curve
plt.scatter(X, Y, label="Data Points")
plt.plot(X_test, Y_pred, label="Locally Weighted Regression")

plt.scatter(
    given_point,
    prediction,
    marker="X",
    s=150,
    label="Prediction"
)

plt.xlabel("X")
plt.ylabel("Y")
plt.title("Locally Weighted Regression")
plt.legend()
plt.show()