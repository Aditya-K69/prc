knowledgebase = {
    "Excellent": ["completes tasks on time", "team player", "innovative", "high productivity"],

    "Good": ["meets deadlines", "cooperative", "consistent"],

    "Average": ["needs supervision", "average productivity", "sometimes late"],

    "Poor": ["misses deadlines", "low productivity", "poor communication"]
}

# Evaluation Function
def evaluation(employee_traits):

    scores = {}

    for level, traits in knowledgebase.items():

        match_cnt = 0

        for trait in traits:
            if trait in employee_traits:
                match_cnt += 1

        score = (match_cnt / len(traits)) * 100
        scores[level] = score

    return scores


# Input from User
n = int(input("Enter number of employee traits: "))

employee_traits = []

for i in range(n):
    trait = input(f"Enter trait {i+1}: ").lower()
    employee_traits.append(trait)


# Evaluate
results = evaluation(employee_traits)

best = max(results, key=results.get)


# Display Results
for level, score in results.items():
    print(f"{level}: {score:.2f}% match")

print("Employee Performance Level:", best)


# Recommendation
if results[best] >= 70:
    print("Recommendation: Employee is performing very well.")
elif results[best] >= 40:
    print("Recommendation: Employee performance is satisfactory.")
else:
    print("Recommendation: Employee needs improvement and guidance.")