from django.http import HttpResponse
from django.shortcuts import render
from django.views import generic

import random


# def index(request):
#    return HttpResponse("hello world!")


class IndexView(generic.TemplateView):
    template_name = "base/index.html"
