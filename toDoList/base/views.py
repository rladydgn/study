from django.http import HttpResponse
from django.shortcuts import render, redirect, get_object_or_404

# Create your views here.
from base.forms import ToDoForm
from base.models import Todo


# 완료 되지 않은 목록 보여줌
def todo_list(request):
    # complete 열이 False인 행만 가져온다.
    # complete=False 도 됨.
    todo = Todo.objects.filter(complete__exact=False)
    return render(request, 'base/todo_list.html', {'todo': todo})


# 투두 리스트 추가, 폼 페이지 이동
def todo_post(request):
    # GET 방식, 페이지 이동
    if request.method == "GET":
        form = ToDoForm()
        return render(request, "base/todo_post.html", {'form': form})

    # POST 방식, 투두 추가
    if request.method == "POST":
        form = ToDoForm(request.POST)
        if form.is_valid():
            todo = form.save()
            todo.save()
            return redirect('todo_list')

    return HttpResponse("failed")


# 투두 수정
def todo_edit(request, pk):
    todo = get_object_or_404(Todo, pk=pk)
    # 투두 수정 페이지 이동
    if request.method == "GET":
        form = ToDoForm(instance=todo)
        return render(request, "base/todo_post.html", {'form': form})

    # 투두 수정 적용
    elif request.method == "POST":
        form = ToDoForm(request.POST, instance=todo)
        if form.is_valid():
            todo = form.save(commit=True)
            todo.save()
            return redirect('todo_list')


# 완료한 투두 목록
def todo_done(request):
    todo = Todo.objects.filter(complete__exact=True)
    return render(request, 'base/todo_done.html', {'todo': todo})


# 투두 완료로 이동
def todo_to_done(request, pk):
    todo = get_object_or_404(Todo, pk=pk)
    todo.complete = True
    todo.save()
    return redirect('todo_list')
