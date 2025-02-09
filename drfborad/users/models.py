from django.contrib.auth.models import User
from django.db import models


# 1대1 관계를 이용하여 유저의 정보들을 추가해 주는 것.
# 개발 측면에선 쉬우나 효율즉면에선 좋지 않다.
# 필요한 유저 정보를 쉽게 추가할 수 있다.
from django.db.models.signals import post_save
from django.dispatch import receiver


class Profile(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE, primary_key=True)
    nickname = models.CharField(max_length=128)
    position = models.CharField(max_length=128)
    subjects = models.CharField(max_length=128)
    image = models.ImageField(upload_to='profile/', default='default.jpg')


# user 모델이 post_save 이벤트를 발생 시켰을 때 자동으로 해당 함수를 실행 시켜줌.
# 자동으로 프로필 데이터가 생성됨
@receiver(post_save, sender=User)
def create_user_profile(sender, instance, created, **kwargs):
    if created:
        Profile.objects.create(user=instance)
