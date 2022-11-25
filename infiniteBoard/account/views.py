from django.contrib.auth import authenticate, login
from django.shortcuts import render, redirect

from account.forms import UserForm


def signup(request):
    if request.method == "POST":
        form = UserForm(request.POST)
        if form.is_valid():
            form.save()
            # 사용자 인증을 담당한다. (사용자명과 비밀번호가 정확한지 검증한다.)
            username = form.cleaned_data.get('username')
            # 로그인을 담당한다. (사용자 세션을 생성한다.)
            password = form.cleaned_data.get('password1')
            user = authenticate(username=username, password=password)
            login(request, user)
            return redirect('board:home')
    else:
        form = UserForm()
    return render(request, 'account/signup.html', {'form': form})
