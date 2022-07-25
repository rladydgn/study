from django.db import models


class Account(models.Model):
    # salt 값에 user_id 를 추가해 해시를 적용시킨 값
    id = models.CharField(max_length=128, primary_key=True)
    # 유저 아이디
    user_id = models.CharField(max_length=15, unique=True)
    phone_number = models.CharField(max_length=30, unique=True)
    email = models.EmailField(unique=True)
    # 유저 비밀번호 salt 값에 비밀번호를 추가해 해시를 적용시킨 값
    password = models.CharField(max_length=20)
    # 비밀 번호 암호화를 위한 salt 값
    salt = models.IntegerField(unique=True)
    is_staff = models.BooleanField(default=False)