# Program 05
# ID3 Decision Tree Algorithm using Play Tennis Dataset

import pandas as pd
import numpy as np
import math
import matplotlib.pyplot as plt
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay


# --------------------------------------------------
# Step 1: Load the dataset
# --------------------------------------------------

data = pd.read_csv("WeatherCondition.csv")

print("===== PLAY TENNIS DATASET =====")
print(data)


# --------------------------------------------------
# Step 2: Calculate Entropy
# --------------------------------------------------

def entropy(target):
    values, counts = np.unique(target, return_counts=True)

    entropy_value = 0

    for count in counts:
        probability = count / len(target)
        entropy_value -= probability * math.log2(probability)

    return entropy_value


# --------------------------------------------------
# Step 3: Calculate Information Gain
# --------------------------------------------------

def information_gain(data, feature, target):

    total_entropy = entropy(data[target])

    values, counts = np.unique(data[feature], return_counts=True)

    weighted_entropy = 0

    for value, count in zip(values, counts):

        subset = data[data[feature] == value]

        weighted_entropy += (
            count / len(data)
        ) * entropy(subset[target])

    gain = total_entropy - weighted_entropy

    return gain


# --------------------------------------------------
# Step 4: ID3 Algorithm
# --------------------------------------------------

def id3(data, features, target):

    # If all target values are same
    if len(np.unique(data[target])) == 1:
        return data[target].iloc[0]

    # If no features are left
    if len(features) == 0:
        return data[target].mode()[0]

    # Calculate information gain for all features
    gains = {}

    for feature in features:
        gains[feature] = information_gain(
            data, feature, target
        )

    # Select feature with maximum information gain
    best_feature = max(gains, key=gains.get)

    tree = {best_feature: {}}

    # Create branches
    for value in np.unique(data[best_feature]):

        subset = data[data[best_feature] == value]

        remaining_features = [
            feature for feature in features
            if feature != best_feature
        ]

        tree[best_feature][value] = id3(
            subset,
            remaining_features,
            target
        )

    return tree


# --------------------------------------------------
# Step 5: Display Information Gain
# --------------------------------------------------

features = [
    "OUTLOOK",
    "TEMPERATURE",
    "HUMIDITY",
    "WIND"
]

target = "PLAY TENNIS"

print("\n===== INFORMATION GAIN =====")

for feature in features:
    gain = information_gain(data, feature, target)
    print(feature, ":", round(gain, 4))


# --------------------------------------------------
# Step 6: Construct ID3 Decision Tree
# --------------------------------------------------

tree = id3(data, features, target)

print("\n===== ID3 DECISION TREE =====")
print(tree)


# --------------------------------------------------
# Step 7: Prediction Function
# --------------------------------------------------

def predict(tree, sample):

    # If tree is already a class
    if not isinstance(tree, dict):
        return tree

    feature = next(iter(tree))

    value = sample[feature]

    subtree = tree[feature][value]

    return predict(subtree, sample)


# --------------------------------------------------
# Step 8: Predict a New Weather Condition
# --------------------------------------------------

new_sample = {
    "OUTLOOK": "Sunny",
    "TEMPERATURE": "Cool",
    "HUMIDITY": "High",
    "WIND": "Strong"
}

prediction = predict(tree, new_sample)

print("\n===== NEW SAMPLE PREDICTION =====")

print("Weather Condition:")
print(new_sample)

print("Predicted Play Tennis:", prediction)


# --------------------------------------------------
# Step 9: Predict all dataset records
# --------------------------------------------------

predictions = []

for index, row in data.iterrows():

    sample = {
        "OUTLOOK": row["OUTLOOK"],
        "TEMPERATURE": row["TEMPERATURE"],
        "HUMIDITY": row["HUMIDITY"],
        "WIND": row["WIND"]
    }

    prediction = predict(tree, sample)

    predictions.append(prediction)


# --------------------------------------------------
# Step 10: Confusion Matrix
# --------------------------------------------------

actual = data[target]

cm = confusion_matrix(
    actual,
    predictions,
    labels=["No", "Yes"]
)

print("\n===== CONFUSION MATRIX =====")
print(cm)


# --------------------------------------------------
# Step 11: Display Confusion Matrix Graphically
# --------------------------------------------------

display = ConfusionMatrixDisplay(
    confusion_matrix=cm,
    display_labels=["No", "Yes"]
)

display.plot(cmap="Blues", values_format="d")

plt.title("ID3 Decision Tree - Confusion Matrix")
plt.xlabel("Predicted")
plt.ylabel("Actual")

plt.show()