import { useEffect, useState } from "react";
import ImageCard from "./components/ImageCard";
import ImageSearch from "./components/ImageSearch";

function App() {
  const [ images, setImages] = useState([]);
  const [isLoading, setIsLoading] = useState(true);
  const [term, setTerm] = useState('');

  

  useEffect(() => {
    let url = `https://pixabay.com/api/?key=${process.env.REACT_APP_PIXABAY_API_KEY}&q=${term}&image_type=photo&pretty=true`;

    fetch(url).then(res => res.json()).then(data => {
      setImages(data.hits);
      setIsLoading(false)})
    .catch(err => console.log(err));
  }, [term]);

  return (
    <div className="container mx-auto">
      <ImageSearch serachText={(text) => setTerm(text)} />

      {!isLoading && images.length === 0 && 
      <h1 className="text-6xl text-center mx-auto mt-32">No Image Found &#128248;...</h1>}
      {isLoading ? 
      <h1 className="text-6xl text-center mx-auto mt-32">Loading...</h1>
      : <div className="grid grid-cols-3 gap-4">
        {images.map(image => (
          <ImageCard key={image.id} image={image}/>
        ))}
      </div>}
      <div className="text-xl mt-32 text-shadow-2xl">Image Gallery By Manoja D &#128248;</div>
    </div>
  );
}

export default App;
