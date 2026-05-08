knowledgebase={
      "Flu": ["fever", "cough", "body pain", "cold"],

    "Measles": ["fever", "rash", "red eyes"],

    "Heart Disease": ["chest pain", "shortness of breath", "fatigue"],

    "Migraine": ["headache", "vomiting", "nausea"],

    "Food Poisoning": ["stomach pain", "diarrhea", "vomiting"]
}

def dignosis(user_symtoms):
    scores={}
    for d,s in knowledgebase.items():
        match_cnt=0
        for symtoms in s:
            if symtoms in user_symtoms:
                match_cnt+=1
        score=(match_cnt/len(s))*100
        scores[d]=score
    return scores

n=int(input("Enter number of symtoms"))
user_symtoms=[]
for i in range(0,n):
    symptom = input(f"Enter symptom {i+1}: ").lower()
    user_symtoms.append(symptom)
results = dignosis(user_symtoms)
best=max(results,key=results.get)
for d,s in results.items():
    print(f"{d}:{s:.2f}% match")
print("high chance ",best)

if results[best]>=70:
    print("Recommendation: High probability. Consult doctor immediately.")
else:
    print("Recommendation: Symptoms unclear. Further diagnosis needed.")




