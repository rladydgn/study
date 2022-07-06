from django.contrib import admin

from .models import Question

# 관리 페이지에 Question model 관리 추가.
admin.site.register(Question)