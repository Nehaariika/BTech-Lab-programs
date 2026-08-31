# Program 03
# K-Nearest Neighbour (KNN) Classification using Iris Dataset

# Import required libraries
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, classification_report

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

# Step 4: Standardize the features
scaler = StandardScaler()

X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Step 5: Create the KNN classifier
k = 3

knn = KNeighborsClassifier(n_neighbors=k)

# Step 6: Train the model
knn.fit(X_train, y_train)

# Step 7: Predict the test data
y_pred = knn.predict(X_test)

# Step 8: Calculate accuracy
accuracy = accuracy_score(y_test, y_pred)

print("\nKNN Classification Accuracy:",
      accuracy * 100, "%")

# Step 9: Classify a new data sample
# [Sepal Length, Sepal Width, Petal Length, Petal Width]

new_sample = np.array([[5.1, 3.5, 1.4, 0.2]])

# Standardize the new sample
new_sample_scaled = scaler.transform(new_sample)

# Predict the class
prediction = knn.predict(new_sample_scaled)

# Display the predicted class
print("\nNew Data Sample:")
print(new_sample)

print("\nPredicted Class:",
      iris.target_names[prediction[0]])

# Step 10: Display classification report
print("\nClassification Report:")
print(classification_report(
    y_test,
    y_pred,
    target_names=iris.target_names
))

# Plot the Iris dataset
plt.scatter(
    X[:, 2],
    X[:, 3],
    c=y,
    cmap='viridis',
    label='Iris Data'
)

# Plot the new sample
plt.scatter(
    new_sample[0, 2],
    new_sample[0, 3],
    color='red',
    marker='*',
    s=200,
    label='New Sample'
)

plt.xlabel('Petal Length (cm)')
plt.ylabel('Petal Width (cm)')
plt.title('KNN Classification - Iris Dataset')
plt.legend()
plt.grid(True)

plt.show()