// Online Exam System
// A simple C++ implementation with classes, file handling, and timer functionality

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <limits>

// Constants for array sizes
const int MAX_QUESTIONS = 100;
const int MAX_OPTIONS = 4;
const int MAX_USERS = 50;
const int MAX_EXAMS = 20;
const int MAX_RESPONSES = 100;
const int STRING_SIZE = 256;

class Timer
{
private:
    time_t startTime;
    time_t endTime;
    int durationInSeconds;
    bool isRunning;

public:
    Timer() : startTime(0), endTime(0), durationInSeconds(0), isRunning(false) {}

    void setDuration(int seconds)
    {
        durationInSeconds = seconds;
    }

    void start()
    {
        startTime = time(NULL);
        isRunning = true;
    }

    void stop()
    {
        if (isRunning)
        {
            endTime = time(NULL);
            isRunning = false;
        }
    }

    int getElapsedTime()
    {
        if (isRunning)
        {
            return time(NULL) - startTime;
        }
        else
        {
            return endTime - startTime;
        }
    }

    int getRemainingTime()
    {
        if (!isRunning)
            return 0;
        int elapsed = getElapsedTime();
        if (elapsed >= durationInSeconds)
            return 0;
        return durationInSeconds - elapsed;
    }

    bool isTimeUp()
    {
        if (!isRunning)
            return true;
        return getElapsedTime() >= durationInSeconds;
    }

    void displayTime()
    {
        int timeLeft = getRemainingTime();
        int minutes = timeLeft / 60;
        int seconds = timeLeft % 60;
        std::cout << "\rTime remaining: " << minutes << ":" << std::setfill('0')
                  << std::setw(2) << seconds << "   " << std::flush;
    }
};

class Question
{
private:
    int id;
    char questionText[STRING_SIZE];
    char options[MAX_OPTIONS][STRING_SIZE];
    char correctAnswer[STRING_SIZE];
    int marks;
    char questionType[20]; // "MCQ", "Essay", "ShortAnswer"

public:
    Question()
    {
        id = 0;
        strcpy_s(questionText, "");
        for (int i = 0; i < MAX_OPTIONS; i++)
        {
            strcpy_s(options[i], "");
        }
        strcpy_s(correctAnswer, "");
        marks = 0;
        strcpy_s(questionType, "");
    }

    void setQuestion(int qid, const char *text, const char *opt[], const char *answer, int qmarks, const char *type)
    {
        id = qid;
        strcpy_s(questionText, text);

        int optCount = 0;
        if (strcmp(type, "MCQ") == 0)
        {
            optCount = MAX_OPTIONS;
        }

        for (int i = 0; i < optCount; i++)
        {
            strcpy_s(options[i], opt[i]);
        }

        strcpy_s(correctAnswer, answer);
        marks = qmarks;
        strcpy_s(questionType, type);
    }

    void displayQuestion() const
    {
        std::cout << "\nQuestion " << id << " (" << marks << " marks) [" << questionType << "]" << std::endl;
        std::cout << questionText << std::endl;

        if (strcmp(questionType, "MCQ") == 0)
        {
            for (int i = 0; i < MAX_OPTIONS; i++)
            {
                if (strlen(options[i]) > 0)
                {
                    std::cout << char('A' + i) << ". " << options[i] << std::endl;
                }
            }
        }
    }

    bool checkAnswer(const char *answer) const
    {
        return strcmp(answer, correctAnswer) == 0;
    }

    int getId() const { return id; }
    const char *getQuestionType() const { return questionType; }
    int getMarks() const { return marks; }
    const char *getCorrectAnswer() const { return correctAnswer; }
};

class User
{
private:
    int id;
    char username[50];
    char password[50];
    char role[20]; // "admin" or "student"

public:
    User() : id(0)
    {
        strcpy_s(username, "");
        strcpy_s(password, "");
        strcpy_s(role, "");
    }

    void setUser(int uid, const char *uname, const char *pwd, const char *r)
    {
        id = uid;
        strcpy_s(username, uname);
        strcpy_s(password, pwd);
        strcpy_s(role, r);
    }

    bool authenticate(const char *uname, const char *pwd) const
    {
        return (strcmp(username, uname) == 0 && strcmp(password, pwd) == 0);
    }

    int getId() const { return id; }
    const char *getUsername() const { return username; }
    const char *getRole() const { return role; }
};

class Exam
{
private:
    int id;
    char title[100];
    char description[STRING_SIZE];
    int questionIds[MAX_QUESTIONS];
    int questionCount;
    int duration; // in seconds
    bool published;

public:
    Exam() : id(0), questionCount(0), duration(3600), published(false)
    {
        strcpy_s(title, "");
        strcpy_s(description, "");
        for (int i = 0; i < MAX_QUESTIONS; i++)
        {
            questionIds[i] = 0;
        }
    }

    void setExam(int eid, const char *t, const char *desc, int dur)
    {
        id = eid;
        strcpy_s(title, t);
        strcpy_s(description, desc);
        duration = dur;
    }

    void addQuestion(int qid)
    {
        if (questionCount < MAX_QUESTIONS)
        {
            questionIds[questionCount++] = qid;
        }
    }

    void publishExam()
    {
        published = true;
    }

    bool isPublished() const
    {
        return published;
    }

    int getId() const { return id; }
    const char *getTitle() const { return title; }
    const char *getDescription() const { return description; }
    int getDuration() const { return duration; }
    int getQuestionCount() const { return questionCount; }

    int getQuestionId(int index) const
    {
        if (index >= 0 && index < questionCount)
        {
            return questionIds[index];
        }
        return -1;
    }

    void displayInfo() const
    {
        std::cout << "Exam ID: " << id << std::endl;
        std::cout << "Title: " << title << std::endl;
        std::cout << "Description: " << description << std::endl;
        std::cout << "Duration: " << duration / 60 << " minutes" << std::endl;
        std::cout << "Number of questions: " << questionCount << std::endl;
        std::cout << "Status: " << (published ? "Published" : "Draft") << std::endl;
    }
};

class Response
{
private:
    int id;
    int examId;
    int userId;
    time_t startTime;
    time_t endTime;
    int questionIds[MAX_QUESTIONS];
    char answers[MAX_QUESTIONS][STRING_SIZE];
    int marks[MAX_QUESTIONS];
    int questionCount;
    int totalMarks;
    char comments[STRING_SIZE];

public:
    Response() : id(0), examId(0), userId(0), startTime(0), endTime(0), questionCount(0), totalMarks(0)
    {
        strcpy_s(comments, "");
        for (int i = 0; i < MAX_QUESTIONS; i++)
        {
            questionIds[i] = 0;
            strcpy_s(answers[i], "");
            marks[i] = 0;
        }
    }

    void startExam(int rid, int eid, int uid)
    {
        id = rid;
        examId = eid;
        userId = uid;
        startTime = time(NULL);
    }

    void endExam()
    {
        endTime = time(NULL);
    }

    void setQuestionCount(int count)
    {
        questionCount = (count <= MAX_QUESTIONS) ? count : MAX_QUESTIONS;
    }

    void setQuestionId(int index, int qid)
    {
        if (index >= 0 && index < questionCount)
        {
            questionIds[index] = qid;
        }
    }

    void setAnswer(int index, const char *ans)
    {
        if (index >= 0 && index < questionCount)
        {
            strcpy_s(answers[index], ans);
        }
    }

    void setMark(int index, int mark)
    {
        if (index >= 0 && index < questionCount)
        {
            marks[index] = mark;
            calculateTotalMarks();
        }
    }

    void setComments(const char *cmt)
    {
        strcpy_s(comments, cmt);
    }

    void calculateTotalMarks()
    {
        totalMarks = 0;
        for (int i = 0; i < questionCount; i++)
        {
            totalMarks += marks[i];
        }
    }

    int getId() const { return id; }
    int getExamId() const { return examId; }
    int getUserId() const { return userId; }
    int getQuestionCount() const { return questionCount; }
    int getTotalMarks() const { return totalMarks; }
    const char *getComments() const { return comments; }
    time_t getStartTime() const { return startTime; }
    time_t getEndTime() const { return endTime; }

    int getQuestionId(int index) const
    {
        if (index >= 0 && index < questionCount)
        {
            return questionIds[index];
        }
        return -1;
    }

    const char *getAnswer(int index) const
    {
        if (index >= 0 && index < questionCount)
        {
            return answers[index];
        }
        return "";
    }

    int getMark(int index) const
    {
        if (index >= 0 && index < questionCount)
        {
            return marks[index];
        }
        return 0;
    }

    int getTimeTaken() const
    {
        return endTime - startTime;
    }
};

class ExamSystem
{
private:
    User users[MAX_USERS];
    int userCount;
    Question questions[MAX_QUESTIONS];
    int questionCount;
    Exam exams[MAX_EXAMS];
    int examCount;
    Response responses[MAX_RESPONSES];
    int responseCount;
    int currentUserId;

    // File paths
    const char *USER_FILE = "users.dat";
    const char *QUESTION_FILE = "questions.dat";
    const char *EXAM_FILE = "exams.dat";
    const char *RESPONSE_FILE = "responses.dat";

public:
    ExamSystem() : userCount(0), questionCount(0), examCount(0), responseCount(0), currentUserId(-1)
    {
        loadData();
    }

    ~ExamSystem()
    {
        saveData();
    }

    void loadData()
    {
        loadUsers();
        loadQuestions();
        loadExams();
        loadResponses();
    }

    void saveData()
    {
        saveUsers();
        saveQuestions();
        saveExams();
        saveResponses();
    }

    void loadUsers()
    {
        std::ifstream file(USER_FILE, std::ios::binary);
        if (file.is_open())
        {
            file.read(reinterpret_cast<char *>(&userCount), sizeof(userCount));
            file.read(reinterpret_cast<char *>(users), sizeof(User) * userCount);
            file.close();
        }
    }

    void saveUsers()
    {
        std::ofstream file(USER_FILE, std::ios::binary);
        if (file.is_open())
        {
            file.write(reinterpret_cast<const char *>(&userCount), sizeof(userCount));
            file.write(reinterpret_cast<const char *>(users), sizeof(User) * userCount);
            file.close();
        }
    }

    void loadQuestions()
    {
        std::ifstream file(QUESTION_FILE, std::ios::binary);
        if (file.is_open())
        {
            file.read(reinterpret_cast<char *>(&questionCount), sizeof(questionCount));
            file.read(reinterpret_cast<char *>(questions), sizeof(Question) * questionCount);
            file.close();
        }
    }

    void saveQuestions()
    {
        std::ofstream file(QUESTION_FILE, std::ios::binary);
        if (file.is_open())
        {
            file.write(reinterpret_cast<const char *>(&questionCount), sizeof(questionCount));
            file.write(reinterpret_cast<const char *>(questions), sizeof(Question) * questionCount);
            file.close();
        }
    }

    void loadExams()
    {
        std::ifstream file(EXAM_FILE, std::ios::binary);
        if (file.is_open())
        {
            file.read(reinterpret_cast<char *>(&examCount), sizeof(examCount));
            file.read(reinterpret_cast<char *>(exams), sizeof(Exam) * examCount);
            file.close();
        }
    }

    void saveExams()
    {
        std::ofstream file(EXAM_FILE, std::ios::binary);
        if (file.is_open())
        {
            file.write(reinterpret_cast<const char *>(&examCount), sizeof(examCount));
            file.write(reinterpret_cast<const char *>(exams), sizeof(Exam) * examCount);
            file.close();
        }
    }

    void loadResponses()
    {
        std::ifstream file(RESPONSE_FILE, std::ios::binary);
        if (file.is_open())
        {
            file.read(reinterpret_cast<char *>(&responseCount), sizeof(responseCount));
            file.read(reinterpret_cast<char *>(responses), sizeof(Response) * responseCount);
            file.close();
        }
    }

    void saveResponses()
    {
        std::ofstream file(RESPONSE_FILE, std::ios::binary);
        if (file.is_open())
        {
            file.write(reinterpret_cast<const char *>(&responseCount), sizeof(responseCount));
            file.write(reinterpret_cast<const char *>(responses), sizeof(Response) * responseCount);
            file.close();
        }
    }

    bool login(const char *username, const char *password)
    {
        for (int i = 0; i < userCount; i++)
        {
            if (users[i].authenticate(username, password))
            {
                currentUserId = users[i].getId();
                return true;
            }
        }
        return false;
    }

    void logout()
    {
        currentUserId = -1;
    }

    bool isAdmin() const
    {
        if (currentUserId == -1)
            return false;

        for (int i = 0; i < userCount; i++)
        {
            if (users[i].getId() == currentUserId)
            {
                return strcmp(users[i].getRole(), "admin") == 0;
            }
        }
        return false;
    }

    void addUser(const char *username, const char *password, const char *role)
    {
        if (userCount < MAX_USERS)
        {
            users[userCount].setUser(userCount + 1, username, password, role);
            userCount++;
            saveUsers();
        }
    }

    void addQuestion(const char *text, const char *options[], const char *answer, int marks, const char *type)
    {
        if (questionCount < MAX_QUESTIONS)
        {
            questions[questionCount].setQuestion(questionCount + 1, text, options, answer, marks, type);
            questionCount++;
            saveQuestions();
        }
    }

    void createExam(const char *title, const char *description, int duration)
    {
        if (examCount < MAX_EXAMS)
        {
            exams[examCount].setExam(examCount + 1, title, description, duration);
            examCount++;
            saveExams();
        }
    }

    void addQuestionToExam(int examId, int questionId)
    {
        for (int i = 0; i < examCount; i++)
        {
            if (exams[i].getId() == examId)
            {
                exams[i].addQuestion(questionId);
                saveExams();
                break;
            }
        }
    }

    void publishExam(int examId)
    {
        for (int i = 0; i < examCount; i++)
        {
            if (exams[i].getId() == examId)
            {
                exams[i].publishExam();
                saveExams();
                break;
            }
        }
    }

    // Find exam by ID
    int findExamIndex(int examId) const
    {
        for (int i = 0; i < examCount; i++)
        {
            if (exams[i].getId() == examId)
            {
                return i;
            }
        }
        return -1;
    }

    // Find question by ID
    int findQuestionIndex(int questionId) const
    {
        for (int i = 0; i < questionCount; i++)
        {
            if (questions[i].getId() == questionId)
            {
                return i;
            }
        }
        return -1;
    }

    int takeExam(int examId)
    {
        int examIndex = findExamIndex(examId);

        if (examIndex == -1 || !exams[examIndex].isPublished())
        {
            return -1; // Exam doesn't exist or is not published
        }

        // Create a new response
        if (responseCount >= MAX_RESPONSES)
        {
            return -1; // Too many responses
        }

        int responseId = responseCount + 1;
        responses[responseCount].startExam(responseId, examId, currentUserId);
        responses[responseCount].setQuestionCount(exams[examIndex].getQuestionCount());

        for (int i = 0; i < exams[examIndex].getQuestionCount(); i++)
        {
            int qid = exams[examIndex].getQuestionId(i);
            responses[responseCount].setQuestionId(i, qid);
        }

        // Set up timer
        Timer examTimer;
        examTimer.setDuration(exams[examIndex].getDuration());
        examTimer.start();

        // Display exam information
        std::cout << "\n===== " << exams[examIndex].getTitle() << " =====" << std::endl;
        std::cout << exams[examIndex].getDescription() << std::endl;
        std::cout << "Duration: " << exams[examIndex].getDuration() / 60 << " minutes" << std::endl;
        std::cout << "Number of questions: " << exams[examIndex].getQuestionCount() << std::endl;
        std::cout << "Press Enter to start the exam..." << std::endl;
        std::cin.ignore();
        std::cin.get();

        // Answer each question
        for (int i = 0; i < exams[examIndex].getQuestionCount() && !examTimer.isTimeUp(); i++)
        {
            int qid = exams[examIndex].getQuestionId(i);
            int qIndex = findQuestionIndex(qid);

            if (qIndex != -1)
            {
                // Display timer
                examTimer.displayTime();

                // Display question
                questions[qIndex].displayQuestion();

                // Get answer
                char answer[STRING_SIZE];
                std::cout << "Your answer: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.getline(answer, STRING_SIZE);

                // Save answer
                responses[responseCount].setAnswer(i, answer);
            }

            // Check time after each question
            if (examTimer.isTimeUp())
            {
                std::cout << "\nTime's up!" << std::endl;
                break;
            }
        }

        // End the exam
        examTimer.stop();
        responses[responseCount].endExam();

        // Grade MCQ questions automatically
        for (int i = 0; i < exams[examIndex].getQuestionCount(); i++)
        {
            int qid = exams[examIndex].getQuestionId(i);
            int qIndex = findQuestionIndex(qid);

            if (qIndex != -1 && strcmp(questions[qIndex].getQuestionType(), "MCQ") == 0)
            {
                const char *answer = responses[responseCount].getAnswer(i);
                if (questions[qIndex].checkAnswer(answer))
                {
                    responses[responseCount].setMark(i, questions[qIndex].getMarks());
                }
                else
                {
                    responses[responseCount].setMark(i, 0);
                }
            }
        }

        responseCount++;
        saveResponses();
        return responseId;
    }

    void gradeExam(int responseId)
    {
        int responseIndex = -1;
        for (int i = 0; i < responseCount; i++)
        {
            if (responses[i].getId() == responseId)
            {
                responseIndex = i;
                break;
            }
        }

        if (responseIndex == -1)
        {
            std::cout << "Response not found." << std::endl;
            return;
        }

        int examId = responses[responseIndex].getExamId();
        int examIndex = findExamIndex(examId);

        if (examIndex == -1)
        {
            std::cout << "Exam not found." << std::endl;
            return;
        }

        std::cout << "\n===== Grading: " << exams[examIndex].getTitle() << " =====" << std::endl;

        for (int i = 0; i < responses[responseIndex].getQuestionCount(); i++)
        {
            int qid = responses[responseIndex].getQuestionId(i);
            int qIndex = findQuestionIndex(qid);

            if (qIndex != -1)
            {
                // Skip MCQs as they are auto-graded
                if (strcmp(questions[qIndex].getQuestionType(), "MCQ") == 0)
                {
                    continue;
                }

                questions[qIndex].displayQuestion();
                std::cout << "Student's answer: " << responses[responseIndex].getAnswer(i) << std::endl;

                if (strcmp(questions[qIndex].getQuestionType(), "Essay") == 0 ||
                    strcmp(questions[qIndex].getQuestionType(), "ShortAnswer") == 0)
                {
                    std::cout << "Maximum marks: " << questions[qIndex].getMarks() << std::endl;
                    std::cout << "Enter marks for this question: ";
                    int marks;
                    std::cin >> marks;

                    if (marks >= 0 && marks <= questions[qIndex].getMarks())
                    {
                        responses[responseIndex].setMark(i, marks);
                    }
                    else
                    {
                        std::cout << "Invalid marks. Must be between 0 and " << questions[qIndex].getMarks() << std::endl;
                        i--; // Retry
                    }
                }
            }
        }

        std::cout << "Enter comments (if any): ";
        char comments[STRING_SIZE];
        std::cin.ignore();
        std::cin.getline(comments, STRING_SIZE);
        responses[responseIndex].setComments(comments);

        responses[responseIndex].calculateTotalMarks();
        saveResponses();

        std::cout << "Grading completed. Total marks: " << responses[responseIndex].getTotalMarks() << std::endl;
    }

    void viewResult(int responseId)
    {
        int responseIndex = -1;
        for (int i = 0; i < responseCount; i++)
        {
            if (responses[i].getId() == responseId)
            {
                responseIndex = i;
                break;
            }
        }

        if (responseIndex == -1)
        {
            std::cout << "Response not found." << std::endl;
            return;
        }

        int examId = responses[responseIndex].getExamId();
        int examIndex = findExamIndex(examId);

        if (examIndex == -1)
        {
            std::cout << "Exam not found." << std::endl;
            return;
        }

        std::cout << "\n===== Result: " << exams[examIndex].getTitle() << " =====" << std::endl;

        // Find user name
        std::string username = "Unknown";
        int userId = responses[responseIndex].getUserId();
        for (int i = 0; i < userCount; i++)
        {
            if (users[i].getId() == userId)
            {
                username = users[i].getUsername();
                break;
            }
        }

        std::cout << "Student: " << username << std::endl;

        // Format dates
        char startTime[30];
        char endTime[30];
        struct tm *timeinfo;

        timeinfo = localtime(&responses[responseIndex].getStartTime());
        strftime(startTime, sizeof(startTime), "%Y-%m-%d %H:%M:%S", timeinfo);

        timeinfo = localtime(&responses[responseIndex].getEndTime());
        strftime(endTime, sizeof(endTime), "%Y-%m-%d %H:%M:%S", timeinfo);

        std::cout << "Started: " << startTime << std::endl;
        std::cout << "Finished: " << endTime << std::endl;

        int duration = responses[responseIndex].getTimeTaken();
        int minutes = duration / 60;
        int seconds = duration % 60;
        std::cout << "Time taken: " << minutes << " minutes " << seconds << " seconds" << std::endl;

        int maxMarks = 0;
        for (int i = 0; i < responses[responseIndex].getQuestionCount(); i++)
        {
            int qid = responses[responseIndex].getQuestionId(i);
            int qIndex = findQuestionIndex(qid);
            if (qIndex != -1)
            {
                maxMarks += questions[qIndex].getMarks();
            }
        }

        std::cout << "Total marks: " << responses[responseIndex].getTotalMarks()
                  << " out of " << maxMarks << std::endl;

        double percentage = (static_cast<double>(responses[responseIndex].getTotalMarks()) / maxMarks) * 100;
        std::cout << "Percentage: " << std::fixed << std::setprecision(2) << percentage << "%" << std::endl;

        if (!strlen(responses[responseIndex].getComments()) == 0)
        {
            std::cout << "Comments: " << responses[responseIndex].getComments() << std::endl;
        }

        std::cout << "\nQuestion-wise breakdown:" << std::endl;
        for (int i = 0; i < responses[responseIndex].getQuestionCount(); i++)
        {
            int qid = responses[responseIndex].getQuestionId(i);
            int qIndex = findQuestionIndex(qid);

            if (qIndex != -1)
            {
                std::cout << "Q" << (i + 1) << ": " << responses[responseIndex].getMark(i)
                          << "/" << questions[qIndex].getMarks() << std::endl;
            }
        }
    }

    void listExams()
    {
        std::cout << "\n===== Available Exams =====" << std::endl;
        for (int i = 0; i < examCount; i++)
        {
            if (exams[i].isPublished())
            {
                std::cout << exams[i].getId() << ". " << exams[i].getTitle()
                          << " (" << exams[i].getDuration() / 60 << " minutes, "
                          << exams[i].getQuestionCount() << " questions)" << std::endl;
            }
        }
    }

    void adminMenu()
    {
        int choice = 0;
        while (choice != 9)
        {
            std::cout << "\n===== Admin Menu =====" << std::endl;
            std::cout << "1. Add User" << std::endl;
            std::cout << "2. Add Question" << std::endl;
            std::cout << "3. Create Exam" << std::endl;
            std::cout << "4. Add Question to Exam" << std::endl;
            std::cout << "5. Publish Exam" << std::endl;
            std::cout << "6. Grade Exam" << std::endl;
            std::cout << "7. View Results" << std::endl;
            std::cout << "8. List All Exams" << std::endl;
            std::cout << "9. Logout" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
            {
                char username[50], password[50], role[20];
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Enter role (admin/student): ";
                std::cin >> role;
                addUser(username, password, role);
                std::cout << "User added successfully!" << std::endl;
                break;
            }
            case 2:
            {
                char text[STRING_SIZE], type[20], answer[STRING_SIZE];
                char options[MAX_OPTIONS][STRING_SIZE];
                int marks;

                std::cout << "Enter question text: ";
                std::cin.ignore();
                std::cin.getline(text, STRING_SIZE);

                std::cout << "Enter question type (MCQ/Essay/ShortAnswer): ";
                std::cin >> type;

                if (strcmp(type, "MCQ") == 0)
                {
                    for (int i = 0; i < MAX_OPTIONS; i++)
                    {
                        std::cout << "Enter option " << char('A' + i) << " (empty to stop): ";
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.getline(options[i], STRING_SIZE);
                        if (strlen(options[i]) == 0 && i >= 2)
                            break;
                    }
                }

                std::cout << "Enter correct answer: ";
                if (strcmp(type, "MCQ") != 0)
                    std::cin.ignore();
                std::cin.getline(answer, STRING_SIZE);

                std::cout << "Enter marks for this question: ";
                std::cin >> marks;

                char *optPtrs[MAX_OPTIONS];
                for (int i = 0; i < MAX_OPTIONS; i++)
                {
                    optPtrs[i] = options[i];
                }

                addQuestion(text, optPtrs, answer, marks, type);
                std::cout << "Question added successfully!" << std::endl;
                break;
            }
            case 3:
            {
                char title[100], description[STRING_SIZE];
                int duration;

                std::cout << "Enter exam title: ";
                std::cin.ignore();
                std::cin.getline(title, 100);

                std::cout << "Enter exam description: ";
                std::cin.getline(description, STRING_SIZE);

                std::cout << "Enter duration in minutes: ";
                std::cin >> duration;

                createExam(title, description, duration * 60);
                std::cout << "Exam created successfully!" << std::endl;
                break;
            }
            case 4:
            {
                int examId, questionId;

                std::cout << "Available exams:" << std::endl;
                for (int i = 0; i < examCount; i++)
                {
                    std::cout << exams[i].getId() << ". " << exams[i].getTitle() << std::endl;
                }
                std::cout << "Enter exam ID: ";
                std::cin >> examId;

                std::cout << "Available questions:" << std::endl;
                for (int i = 0; i < questionCount; i++)
                {
                    std::cout << questions[i].getId() << ". ";
                    // Print question type
                    std::cout << questions[i].getQuestionType() << std::endl;
                }
                std::cout << "Enter question ID: ";
                std::cin >> questionId;

                addQuestionToExam(examId, questionId);
                std::cout << "Question added to exam successfully!" << std::endl;
                break;
            }
            case 5:
            {
                int examId;

                std::cout << "Available exams:" << std::endl;
                for (int i = 0; i < examCount; i++)
                {
                    if (!exams[i].isPublished())
                    {
                        std::cout << exams[i].getId() << ". " << exams[i].getTitle() << std::endl;
                    }
                }
                std::cout << "Enter exam ID to publish: ";
                std::cin >> examId;

                publishExam(examId);
                std::cout << "Exam published successfully!" << std::endl;
                break;
            }
            case 6:
            {
                int responseId;

                std::cout << "Available responses:" << std::endl;
                for (int i = 0; i < responseCount; i++)
                {
                    std::cout << responses[i].getId() << ". Exam: " << responses[i].getExamId()
                              << ", User: " << responses[i].getUserId() << std::endl;
                }
                std::cout << "Enter response ID to grade: ";
                std::cin >> responseId;

                gradeExam(responseId);
                break;
            }
            case 7:
            {
                int responseId;

                std::cout << "Available responses:" << std::endl;
                for (int i = 0; i < responseCount; i++)
                {
                    std::cout << responses[i].getId() << ". Exam: " << responses[i].getExamId()
                              << ", User: " << responses[i].getUserId() << std::endl;
                }
                std::cout << "Enter response ID to view: ";
                std::cin >> responseId;

                viewResult(responseId);
                break;
            }
            case 8:
            {
                std::cout << "All exams:" << std::endl;
                for (int i = 0; i < examCount; i++)
                {
                    exams[i].displayInfo();
                    std::cout << "---------------------" << std::endl;
                }
                break;
            }
            case 9:
                logout();
                std::cout << "Logged out successfully!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    void studentMenu()
    {
        int choice = 0;
        while (choice != 4)
        {
            std::cout << "\n===== Student Menu =====" << std::endl;
            std::cout << "1. View Available Exams" << std::endl;
            std::cout << "2. Take Exam" << std::endl;
            std::cout << "3. View Results" << std::endl;
            std::cout << "4. Logout" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                listExams();
                break;
            case 2:
            {
                listExams();
                int examId;
                std::cout << "Enter exam ID to take: ";
                std::cin >> examId;

                int responseId = takeExam(examId);
                if (responseId != -1)
                {
                    std::cout << "Exam completed! Your response ID is " << responseId << std::endl;
                }
                else
                {
                    std::cout << "Failed to take exam. Exam may not exist or is not published." << std::endl;
                }
                break;
            }
            case 3:
            {
                std::cout << "Your exam responses:" << std::endl;
                for (int i = 0; i < responseCount; i++)
                {
                    if (responses[i].getUserId() == currentUserId)
                    {
                        int examId = responses[i].getExamId();
                        int examIndex = findExamIndex(examId);
                        if (examIndex != -1)
                        {
                            std::cout << responses[i].getId() << ". " << exams[examIndex].getTitle() << std::endl;
                        }
                    }
                }

                int responseId;
                std::cout << "Enter response ID to view: ";
                std::cin >> responseId;

                // Check if response belongs to current user
                bool found = false;
                for (int i = 0; i < responseCount; i++)
                {
                    if (responses[i].getId() == responseId && responses[i].getUserId() == currentUserId)
                    {
                        found = true;
                        break;
                    }
                }

                if (found)
                {
                    viewResult(responseId);
                }
                else
                {
                    std::cout << "Response not found or access denied." << std::endl;
                }
                break;
            }
            case 4:
                logout();
                std::cout << "Logged out successfully!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    void run()
    {
        int choice = 0;
        while (choice != 3)
        {
            std::cout << "\n===== Online Exam System =====" << std::endl;
            std::cout << "1. Login" << std::endl;
            std::cout << "2. Register" << std::endl;
            std::cout << "3. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
            {
                char username[50], password[50];
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;

                if (login(username, password))
                {
                    std::cout << "Login successful!" << std::endl;
                    if (isAdmin())
                    {
                        adminMenu();
                    }
                    else
                    {
                        studentMenu();
                    }
                }
                else
                {
                    std::cout << "Invalid username or password." << std::endl;
                }
                break;
            }
            case 2:
            {
                char username[50], password[50];
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;

                addUser(username, password, "student");
                std::cout << "Registration successful! You can now login." << std::endl;
                break;
            }
            case 3:
                std::cout << "Thank you for using the Online Exam System!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
};

int main()
{
    // Initialize the system and seed the random number generator
    srand(time(NULL));

    ExamSystem examSystem;

    // If no users exist, create a default admin user
    std::ifstream file("users.dat", std::ios::binary);
    if (!file.good())
    {
        std::cout << "Initializing system with default admin user..." << std::endl;
        examSystem.addUser("admin", "admin123", "admin");
    }
    file.close();

    examSystem.run();

    return 0;
}