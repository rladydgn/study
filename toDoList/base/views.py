from django.shortcuts import render

# Create your views here.
from base.models import Todo


def todo_list(request):
    todo = Todo.objects.all()
    return render(request, 'base/todo_list.html', {'todo': todo})
