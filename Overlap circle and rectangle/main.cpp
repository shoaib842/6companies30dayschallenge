class Solution {
public:
    bool checkOverlap(double radius, double x_center, double y_center, double x1, double y1, double x2, double y2) {
        auto clamp = [](double center, double mini, double maxi) {
            return std::max(mini, std::min(maxi, center));
        };

        // the closest point to the circle within the rectangle
        double closestX = clamp(x_center, x1, x2);
        double closestY = clamp(y_center, y1, y2);

        // the distance between the circle's center and its closest point
        double distanceX = x_center - closestX;
        double distanceY = y_center - closestY;

        // If the distance < the circle's radius, an intersection occurs.
        return (distanceX * distanceX) + (distanceY * distanceY) <= (radius * radius);
    }
};
