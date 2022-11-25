from django.contrib.auth import authenticate, login
from django.contrib.auth.decorators import login_required
from django.core.paginator import Paginator
from django.shortcuts import render, get_object_or_404, redirect

from account.forms import UserForm
from board.forms import BoardForm, CommentForm
from board.models import Board


def home(request):
    return render(request, 'board/home.html')


def board_list(request):
    # query 없을경우 기본값 1
    page = request.GET.get('page', '1')
    boards = Board.objects.order_by('-created_at')
    # 페이지당 10개
    paginator = Paginator(boards, 10)
    page_board = paginator.get_page(page)
    content = {
        "board_list": page_board
    }
    return render(request, 'board/board_list.html', content)


def board_detail(request, board_id):
    board = get_object_or_404(Board, id=board_id)
    board.viewers += 1
    board.save()
    context = {
        'board': board
    }
    return render(request, 'board/board_detail.html', context)


@login_required(login_url='/account/login')
def board_create(request):
    if request.method == "POST":
        form = BoardForm(request.POST)
        if form.is_valid():
            board = form.save(commit=False)
            board.author = request.user
            board.save()
            return redirect('board:board_detail', board_id=board.id)
    else:
        form = BoardForm()
    context = {
        'form': form
    }
    return render(request, 'board/board_form.html', context)


@login_required(login_url='/account/login')
def comment_create(request, board_id):
    board = get_object_or_404(Board, id=board_id)
    if request.method == "POST":
        form = CommentForm(request.POST)
        if form.is_valid():
            comment = form.save(commit=False)
            comment.author = request.user
            comment.board = board
            comment.save()
            return redirect('board:board_detail', board_id=board_id)
    else:
        form = CommentForm()
    context = {
        'board': board,
        'form': form
    }
    return render(request, 'board/board_detail.html', context)