from django.urls import path

from . import views

urlpatterns = [
    path('', views.PlagiarismIndexAPIView.as_view(), name='plagiarism')
]