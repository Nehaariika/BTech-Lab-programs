# Program 06
# Support Vector Machine (SVM) Multiclass Classification
# Using Iris Dataset

# Import required libraries
import numpy as np
import matplotlib.pyplot as plt

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, confusion_matrix, ConfusionMatrixDisplay


# --------------------------------------------------
# Step 1: Load Iris Dataset
# --------------------------------------------------

iris = load_iris()

X = iris.data
y = iris.target


print("===== SUPPORT VECTOR MACHINE CLASSIFICATION =====")

print("\nFeature Names:")
print(iris.feature_names)

print("\nTarget Classes:")
print(iris.target_names)


# --------------------------------------------------
# Step 2: Split Dataset
# --------------------------------------------------

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.2,
    random_state=42,
    stratify=y
)


# --------------------------------------------------
# Step 3: Feature Scaling
# --------------------------------------------------

scaler = StandardScaler()

X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)


# --------------------------------------------------
# Step 4: Create SVM Classifier
# --------------------------------------------------

model = SVC(
    kernel="linear",
    C=1.0
)


# --------------------------------------------------
# Step 5: Train the Model
# --------------------------------------------------

model.fit(X_train, y_train)


# --------------------------------------------------
# Step 6: Predict Test Data
# --------------------------------------------------

y_pred = model.predict(X_test)


# --------------------------------------------------
# Step 7: Calculate Accuracy
# --------------------------------------------------

accuracy = accuracy_score(y_test, y_pred)

print("\nAccuracy:")
print(accuracy * 100, "%")


# --------------------------------------------------
# Step 8: Confusion Matrix
# --------------------------------------------------

cm = confusion_matrix(y_test, y_pred)

print("\nConfusion Matrix:")
print(cm)


# --------------------------------------------------
# Step 9: Display Confusion Matrix
# --------------------------------------------------

display = ConfusionMatrixDisplay(
    confusion_matrix=cm,
    display_labels=iris.target_names
)

display.plot(cmap="Blues", values_format="d")

plt.title("SVM Multiclass Classification - Iris Dataset")
plt.xlabel("Predicted Class")
plt.ylabel("Actual Class")

plt.show()


# --------------------------------------------------
# Step 10: Classify a New Sample
# --------------------------------------------------

# [Sepal Length, Sepal Width, Petal Length, Petal Width]

new_sample = np.array([
    [5.1, 3.5, 1.4, 0.2]
])


# Scale the new sample
new_sample_scaled = scaler.transform(new_sample)


# Predict the class
prediction = model.predict(new_sample_scaled)


print("\n===== NEW SAMPLE PREDICTION =====")

print("New Sample:")
print(new_sample)

print("\nPredicted Flower Species:")

print(iris.target_names[prediction[0]])