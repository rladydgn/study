from django.contrib import admin
from django.urls import path, include

from base.views import todo_list

urlpatterns = [
    path("", todo_list, name='todo_list')
]
