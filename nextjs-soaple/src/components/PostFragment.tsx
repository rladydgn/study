interface PostFragmentProps {
  post: MyNextApp.Post;
}

export default function PostFragment(props: PostFragmentProps) {
  const {post} = props;

  return (
    <div>
      <img src={post.image} alt="post" width='256px' height='auto'/>
      <h3>{post.title}</h3>
      <p>{post.content}</p>
    </div>
  );
}