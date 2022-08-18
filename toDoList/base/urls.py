from django.contrib import admin
from django.urls import path, include

from base.views import todo_list, todo_post, todo_edit, todo_done, todo_to_done

urlpatterns = [
    path("", todo_list, name='todo_list'),
    path("new/", todo_post, name='todo_post'),
    path("edit/<int:pk>", todo_edit, name="todo_edit"),
    path('done/', todo_done, name='todo_done'),
    path('done/<int:pk>/', todo_to_done, name='todo_to_done')
]
