# Program 04
# Gaussian Naive Bayes Classification using Iris Dataset

# Import required libraries
import numpy as np
import matplotlib.pyplot as plt

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, confusion_matrix, ConfusionMatrixDisplay

# Step 1: Load the Iris dataset
iris = load_iris()

X = iris.data
y = iris.target

# Step 2: Display dataset information
print("Feature Names:")
print(iris.feature_names)

print("\nTarget Names:")
print(iris.target_names)

# Step 3: Split the dataset into training and testing data
X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.2,
    random_state=42
)

# Step 4: Create Gaussian Naive Bayes classifier
model = GaussianNB()

# Step 5: Train the classifier
model.fit(X_train, y_train)

# Step 6: Predict the test data
y_pred = model.predict(X_test)

# Step 7: Calculate accuracy
accuracy = accuracy_score(y_test, y_pred)

print("\nAccuracy:",
      accuracy * 100, "%")

# Step 8: Create confusion matrix
cm = confusion_matrix(y_test, y_pred)

print("\nConfusion Matrix:")
print(cm)

# Step 9: Display confusion matrix graphically
display = ConfusionMatrixDisplay(
    confusion_matrix=cm,
    display_labels=iris.target_names
)

display.plot()

plt.title("Gaussian Naive Bayes - Confusion Matrix")
plt.show()

# Step 10: Classify a new test sample
# [Sepal Length, Sepal Width, Petal Length, Petal Width]

test_sample = np.array([
    [5.1, 3.5, 1.4, 0.2]
])

prediction = model.predict(test_sample)

print("\nTest Sample:")
print(test_sample)

print("\nPredicted Flower Species:",
      iris.target_names[prediction[0]])