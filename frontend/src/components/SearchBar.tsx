interface SearchBarProps {
  city: string;
  setCity: (city: string) => void;
  onSearch: () => void;
}
interface SearchBarProps {
  city: string;
  setCity: (city: string) => void;
  onSearch: () => void;
}

function SearchBar({ city, setCity, onSearch }: SearchBarProps) {
  return (
    <div className="flex gap-3">
      <input
        className="
          rounded-full
          px-5
          py-3
          bg-white/10
          backdrop-blur-md
          border
          border-white/20
          text-white
          outline-none
        "
        value={city}
        onChange={(e) => setCity(e.target.value)}
        onKeyDown={(e) => {
          if (e.key === "Enter") {
            onSearch();
          }
        }}
        placeholder="Search city..."
      />

      <button
        className="
          rounded-full
          px-6
          bg-gray-500
          text-white
          hover:bg-black
          transition
          duration-300
          ease-in-out
          hover:scale-105
        "
        onClick={onSearch}
      >
        Search
      </button>
    </div>
  );
}

export default SearchBar;
