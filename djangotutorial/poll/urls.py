from django.urls import path
from . import views

# 이름 공간 다른 앱들과 name 이 같은 경우 구분해 주어야 한다.
app_name = 'poll'
# name 을 이용하여 html 문서에 {% url %} 을 이용하면 하드코딩 하지 않아도 된다.
urlpatterns = [
    path('', views.index, name='index'),
    # /polls/1/
    path('<int:question_id>/', views.detail, name='detail'),
    # /polls/1/results/
    path('<int:question_id>/results/', views.results, name='results'),
    # /polls/1/vote/
    path('<int:question_id>/vote/', views.vote, name='vote'),
]
