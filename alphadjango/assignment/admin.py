from django.contrib import admin

from .models import CodeFile

# 관리 페이지에 CodeFile model 관리 추가
admin.site.register(CodeFile)
