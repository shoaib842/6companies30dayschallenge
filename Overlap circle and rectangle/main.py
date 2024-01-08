class Solution:
    def checkOverlap(self, radius, x_center, y_center, x1, y1, x2, y2):
        def clamp(center, mini, maxi):
            return max(mini, min(maxi, center))

        # the closest point to the circle within the rectangle
        closestX = clamp(x_center, x1, x2)
        closestY = clamp(y_center, y1, y2)

        # the distance between the circle's center and its closest point
        distanceX = x_center - closestX
        distanceY = y_center - closestY

        # If the distance < the circle's radius, an intersection occurs.
        return (distanceX**2) + (distanceY**2) <= (radius**2)
