from django.db import models


# 주제 내용 생성일
class Question(models.Model):
    subject = models.CharField(max_length=200)
    content = models.TextField()
    create_date = models.DateTimeField()

    def __str__(self):
        return self.subject

# q.answer_set.all() 로 왜래키 참조하는 Answer 객체 불러올 수 있음 q는 Question 객체임


# 주제 답변내용 생성일일
class Answer(models.Model):
    question = models.ForeignKey(Question, on_delete=models.CASCADE)
    content = models.TextField()
    create_date = models.DateTimeField()
