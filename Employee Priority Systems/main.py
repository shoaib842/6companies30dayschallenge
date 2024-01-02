class Solution:
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        unique_employees = set()

        # Arrange access_times in ascending order
        access_times.sort()

        # Iterate through the sorted access_times
        for i in range(len(access_times) - 2):
            employee_name = access_times[i][0]

            # Skip if the employee's name is already in the set
            if employee_name in unique_employees:
                continue

            # Check if the current employee's name matches the one two positions ahead
            if employee_name != access_times[i + 2][0]:
                continue

            # Check if the time difference between the first and third occurrences is less than 100
            if int(access_times[i + 2][1]) - int(access_times[i][1]) < 100:
                unique_employees.add(employee_name)

        # Convert the set to a list and return the final result
        return list(unique_employees)
