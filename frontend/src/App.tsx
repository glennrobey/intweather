import { useState } from "react";
import { getWeather, type Weather } from "./api/weather";
import WeatherCard from "./components/WeatherCard";
import SearchBar from "./components/SearchBar";

function App() {
  const [city, setCity] = useState("");
  const [weather, setWeather] = useState<Weather | null>(null);

  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  async function searchWeather() {
    try {
      setLoading(true);
      setError("");

      const data = await getWeather(city);

      setWeather(data);
    } catch (err) {
      setError("Could not find weather");
      console.error(err);
    } finally {
      setLoading(false);
    }
  }

  return (
    <div
      className="
    min-h-screen
    bg-gradient-to-br
    from-zinc-900
    via-slate-800
    to-zinc-700
    flex
    flex-col
    items-center
    justify-center
    gap-6
  "
    >
      <h1 className="text-5xl font-bold text-white">IntWeather</h1>

      <SearchBar city={city} setCity={setCity} onSearch={searchWeather} />

      {loading && <p>Loading weather...</p>}

      {error && <p>{error}</p>}

      {weather && <WeatherCard weather={weather} />}
    </div>
  );
}

export default App;
