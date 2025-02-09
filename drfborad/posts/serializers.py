from rest_framework import serializers

from posts.models import Post
from users.serializers import ProfileSerializer


class PostSerializer(serializers.ModelSerializer):
    # serializer 안에 serializer. nested serializer
    # 이걸 안쓰면 profile 필드의 pk 값만 나타남.
    profile = ProfileSerializer(read_only=True)

    class Meta:
        model = Post
        fields = ['pk', 'profile', 'title', 'body', 'image', 'published_date', 'likes']


class PostCreateSerializer(serializers.ModelSerializer):
    class Meta:
        model = Post
        fields = ['title', 'category', 'body', 'image']
