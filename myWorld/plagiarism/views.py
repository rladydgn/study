from django.http import HttpResponse
from django.shortcuts import render
from django.views import generic

import random


# def index(request):
#    return HttpResponse("hello world!")
from rest_framework.renderers import TemplateHTMLRenderer
from rest_framework.response import Response
from rest_framework.views import APIView


class IndexView(generic.TemplateView):
    template_name = "plagiarism/index.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['number'] = random.randrange(1, 100)
        return context


class PlagiarismIndexAPIView(APIView):
    renderer_classes = [TemplateHTMLRenderer]
    template_name = "plagiarism/plagiarismIndex.html"

    def get(self, request):
        return Response()
