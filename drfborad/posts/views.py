from django.shortcuts import render
from django_filters.rest_framework import DjangoFilterBackend
from rest_framework import viewsets, status
from rest_framework.decorators import permission_classes, api_view
from rest_framework.response import Response

from posts.models import Post
from posts.permissions import CustomReadOnly
from posts.serializers import PostSerializer, PostCreateSerializer
from users.models import Profile


class PostViewSet(viewsets.ModelViewSet):
    queryset = Post.objects.all()
    permission_classes = [CustomReadOnly]
    # 검색 쿼리 스트링 필터
    filter_backends = [DjangoFilterBackend]
    # http://127.0.0.1:8000/view/posts/?author=dhdgn
    filterset_fields = ['author', 'likes']

    def get_serializer_class(self):
        if self.action == ('list' or 'retrieve'):
            return PostSerializer
        return PostCreateSerializer

    def perform_create(self, serializer):
        profile = Profile.objects.get(user=self.request.user)
        serializer.save(author=self.request.user, profile=profile)


@permission_classes([CustomReadOnly])
@api_view(['GET'])
def likes(request, pk):
    post = Post.objects.get(pk=pk)
    if request.user in post.likes.all():
        post.likes.remove(request.user)
    else:
        post.likes.add(request.user)
    print(post.likes.all())
    return Response({'status': ' ok'})
