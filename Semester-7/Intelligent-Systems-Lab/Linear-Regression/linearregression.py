# Import required libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Load the dataset
# Replace 'student_scores.csv' with your dataset file name
data = pd.read_csv('student_scores.csv')

# Independent variable (Hours Studied)
X = data[['Hours']]

# Dependent variable (Marks Scored)
y = data['Scores']

# Create and train the model
model = LinearRegression()
model.fit(X, y)

# Predict marks
predicted_marks = model.predict(X)

# Predict marks for a new student (Example: 9.25 study hours)
hours = np.array([[9.25]])
prediction = model.predict(hours)

print("Predicted Marks for 9.25 study hours =", prediction[0])

# Plot the data points
plt.scatter(X, y, color='blue', label='Actual Data')

# Plot the regression line
plt.plot(X, predicted_marks, color='red', label='Regression Line')

plt.title('Student Score Prediction')
plt.xlabel('Hours Studied')
plt.ylabel('Marks Scored')
plt.legend()

plt.show()