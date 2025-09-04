#include<array>
#include<cmath>
#include<iostream>

double calculateGrade(double midTermScore, double finalScore, std::array<int, 5> projectScors) 
{
    if (midTermScore < finalScore) midTermScore = finalScore;
    const double weightedExamScore = 3.0/4.0 * finalScore + 1.0/4.0 * midTermScore;

    double projectAverage = 0;
    for (double projectScore: projectScors)
    {
        if (projectScore < finalScore) projectScore = finalScore;
        projectAverage += projectScore;
    }
    projectAverage /= projectScors.size();

    if (weightedExamScore >= 60.0) 
        return 2.0/3.0 * weightedExamScore + 1.0/3.0 * projectAverage;
    if (weightedExamScore <= 40.0)
        return weightedExamScore;
    return weightedExamScore * (projectAverage - weightedExamScore) / 60.0 + (5.0 * weightedExamScore - 2.0*projectAverage) / 3.0;
}

int main()
{
    std::array<int, 5> projectScores {95, 95, 95, 95, 95};
    const double score {calculateGrade(65.0, 74.0, projectScores)};
    std::cout << score << std::endl;
    return 0;
}
