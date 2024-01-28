class Solution:
    def asteroidsDestroyed(self, mass, asteroids):
        asteroids.sort()

        m = mass

        for asteroid in asteroids:
            if m >= asteroid:
                m += asteroid
            else:
                return False

        return True
