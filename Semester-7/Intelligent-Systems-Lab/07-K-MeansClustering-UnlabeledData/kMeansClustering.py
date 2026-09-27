# Program 07
# K-Means Clustering

import numpy as np
import matplotlib.pyplot as plt

from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans


# --------------------------------------------------
# Step 1: Generate unlabeled data
# --------------------------------------------------

X, _ = make_blobs(
    n_samples=300,
    centers=4,
    cluster_std=1.0,
    random_state=42
)

print("===== K-MEANS CLUSTERING =====")

print("\nNumber of data points:", len(X))
print("Number of features:", X.shape[1])


# --------------------------------------------------
# Step 2: Select number of clusters
# --------------------------------------------------

k = 4

print("\nNumber of clusters (K):", k)


# --------------------------------------------------
# Step 3: Initialize K-Means
# --------------------------------------------------

kmeans = KMeans(
    n_clusters=k,
    random_state=42,
    n_init=10
)


# --------------------------------------------------
# Step 4: Fit the model
# --------------------------------------------------

kmeans.fit(X)


# --------------------------------------------------
# Step 5: Obtain cluster labels
# --------------------------------------------------

labels = kmeans.labels_

print("\nCluster Labels:")
print(labels)


# --------------------------------------------------
# Step 6: Obtain cluster centroids
# --------------------------------------------------

centroids = kmeans.cluster_centers_

print("\nCluster Centroids:")

for i, centroid in enumerate(centroids):
    print(
        "Cluster", i + 1,
        ":", centroid
    )


# --------------------------------------------------
# Step 7: Calculate inertia
# --------------------------------------------------

inertia = kmeans.inertia_

print("\nInertia:")
print(inertia)


# --------------------------------------------------
# Step 8: Plot the clusters
# --------------------------------------------------

plt.figure(figsize=(8, 6))

plt.scatter(
    X[:, 0],
    X[:, 1],
    c=labels,
    cmap="viridis",
    s=50
)

# Plot centroids
plt.scatter(
    centroids[:, 0],
    centroids[:, 1],
    marker="X",
    s=250,
    color="red",
    edgecolor="black",
    label="Centroids"
)

plt.xlabel("Feature 1")
plt.ylabel("Feature 2")

plt.title("K-Means Clustering")

plt.legend()
plt.grid(True)

plt.show()