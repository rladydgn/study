from django import forms

from board.models import Board, Comment


class BoardForm(forms.ModelForm):
    class Meta:
        model = Board
        fields = ['title', 'subject', 'content']
        labels = {
            'title': '제목',
            'subject': '주제',
            'content': '내용',
        }


class CommentForm(forms.ModelForm):
    class Meta:
        model = Comment
        fields = ['content']
