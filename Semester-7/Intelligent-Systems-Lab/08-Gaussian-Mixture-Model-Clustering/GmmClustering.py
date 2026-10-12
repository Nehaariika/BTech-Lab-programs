# 08-Gaussian-Mixture-Model-Clustering

import numpy as np
import matplotlib.pyplot as plt
from sklearn.mixture import GaussianMixture
from sklearn.datasets import make_blobs

# a. Generate unlabeled data
X, _ = make_blobs(
    n_samples=300,
    centers=3,
    cluster_std=1.0,
    random_state=42
)

# b. Select the number of clusters
k = 3

# c. Initialize Gaussian Mixture Model
gmm = GaussianMixture(
    n_components=k,
    random_state=42
)

# d. Fit the model
gmm.fit(X)

# e. Obtain cluster labels and probabilities
labels = gmm.predict(X)
probabilities = gmm.predict_proba(X)

# Obtain cluster centers (means)
centroids = gmm.means_

print("Cluster Labels:")
print(labels)

print("\nCluster Probabilities:")
print(probabilities)

print("\nCluster Centers:")
print(centroids)

# f. Plot the clusters
plt.figure(figsize=(8, 6))

plt.scatter(
    X[:, 0],
    X[:, 1],
    c=labels,
    cmap="viridis",
    s=40
)

plt.scatter(
    centroids[:, 0],
    centroids[:, 1],
    marker="X",
    s=200,
    c="red",
    label="Cluster Centers"
)

plt.xlabel("Feature 1")
plt.ylabel("Feature 2")
plt.title("Gaussian Mixture Model Clustering")
plt.legend()
plt.show()

# g. Observe probabilistic clustering
print("\nProbability of first 10 data points belonging to each cluster:")
print(probabilities[:10])