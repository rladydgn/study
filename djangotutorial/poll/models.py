import datetime

from django.db import models
from django.utils import timezone


class Question(models.Model):
    # 질문
    question_text = models.CharField(max_length=200)
    # 발행일
    pub_date = models.DateTimeField('data published')

    # 생성한지 하루 이상이면 True return.
    def was_published_recently(self):
        now = timezone.now()
        return now - datetime.timedelta(days=1) <= self.pub_date <= now

    # 객체 자체를 print 할 경우 실행된다.
    def __str__(self):
        return self.question_text


class Choice(models.Model):
    # 외래키, CASECADE는 row 하나 바꾸면 그거랑 관계된 테이블에 있는 row 까지 다 바꿈.
    # 외래키는 nullable임. 1대다 형식이다. 1쪽이 부분참여.
    question = models.ForeignKey(Question, on_delete=models.CASCADE)
    # 댓글 ?
    choice_text = models.CharField(max_length=200)
    # 투표
    votes = models.IntegerField(default=0)

    def __str__(self):
        return self.choice_text
