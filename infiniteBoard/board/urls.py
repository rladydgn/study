from django.contrib import admin
from django.urls import path, include

from board import views

# namespace
app_name = "board"

urlpatterns = [
    path("", views.home, name='home'),
    path("board/", views.board_list, name='board_list'),
    path('board/create/', views.board_create, name='board_create'),
    path('board/view/<int:board_id>', views.board_detail, name='board_detail'),
    path('comment/create/<int:board_id>', views.comment_create, name='comment_create'),
]
